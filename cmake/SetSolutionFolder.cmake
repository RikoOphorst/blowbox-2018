# This function set_solution_folder is courtesy of Daniel Konings http://www.danielkonings.com/
function (set_solution_folder arg1)
  if (MSVC)
    set(SolutionFolder "${arg1}")
    foreach (Target ${ARGV})
      if (NOT "${Target}" STREQUAL "${SolutionFolder}")
        set_target_properties("${Target}" PROPERTIES FOLDER "${SolutionFolder}")
      endif ()
    endforeach ()
  endif (MSVC)
endfunction (set_solution_folder)