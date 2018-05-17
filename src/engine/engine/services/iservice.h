#pragma once

#include <core/data/string.h>

namespace blowbox
{
  namespace engine
  {
    /**
    * @brief Base class of an IService<T>.
    * 
    * This class contains the base functionality of an IService<T>.
    * The IService<T> and IServiceBase have to be separate because
    * of the way that the IDs work for them. The IServiceBase has
    * the static function GetNewID() which internally stores a static
    * variable in its function scope, which gets incremented every
    * time GetNewID() is called. The IService<T> then has a function
    * called IService<T>::GetID() which in turn statically stores
    * the result of a GetNewID() call in the GetID() function scope.
    * This must happen in a different class (i.e. IService with a
    * different T) in order for it to store a different static
    * result from the GetNewID() function call inside of that class's
    * GetID() function. That GetID() function is subsequently a 
    * static function, allowing it be called from anywhere. That is
    * most importantly being used by engine::Engine in order to slot
    * the services in a 1D-array. Retrieving a service is then as
    * simple as calling services[IService<T>::GetID()].
    */
    class IServiceBase
    {
    public:
      /**
      * @brief Constructs an IServiceBase.
      * @param[in] name The name of the service being created.
      */
      IServiceBase(const String& name);

      /**
      * @brief Destructs an IServiceBase.
      */
      virtual ~IServiceBase();

      /**
      * @brief Pure virtual function that gets invoked when the service needs to get initialized.
      * @remarks This should only be called from engine::Engine and nowhere else.
      */
      virtual void Initialize() = 0;

      /**
      * @brief Pure virtual function that gets invoked when the service needs to be shutdown.
      * @remarks This should only be called from engine::Engine and nowhere else.
      */
      virtual void Shutdown() = 0;

      /** @returns The name of the service. */
      const String& GetName() const;

    protected:
      /**
      * @brief Statically generates a new ID for a service.
      * @see blowbox::engine::IServiceBase
      * @returns A new, never used ID usable to be associated with an IService.
      */
      static size_t GetNewID();

    protected:
      String name_; //!< The name of this service.
    };

    /**
    * @brief A layer on top of IServiceBase, keeping track of T's type.
    * @tparam T The parent service class, e.g. ConfigService.
    * @see blowbox::engine::IServiceBase
    */
    template<typename T>
    class IService : public IServiceBase
    {
    public:
      /**
      * @brief Constructs an IService.
      * @param[in] name The name of the service to be created.
      */
      IService(const String& name);

      /**
      * @brief Destructs an IService.
      */
      virtual ~IService();

      /**
      * @brief Statically retrieve IService<T>'s type ID.
      * @see blowbox::engine::IServiceBase
      */
      static size_t GetID();

    protected:
      size_t id_; //!< The type ID of this IService.
    };

    //------------------------------------------------------------------------------------------------------
    template<typename T>
    inline IService<T>::IService(const String& name) :
      IServiceBase(name),
      id_(GetID())
    {

    }

    //------------------------------------------------------------------------------------------------------
    template<typename T>
    inline IService<T>::~IService()
    {

    }

    //------------------------------------------------------------------------------------------------------
    template<typename T>
    inline size_t IService<T>::GetID()
    {
      static size_t id = IServiceBase::GetNewID();
      return id;
    }
  }
}