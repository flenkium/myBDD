cmake_minimum_required(VERSION 3.2.0)
project(myBDD CXX)

#############################
## set source and header files
set(SRCS type.cpp)
set(HDRS type.hpp)

function(pretend var prefix)
   set(listVar "")
   foreach(f ${ARGN})
      list(APPEND listVar "${prefix}/${f}")
   endforeach(f)
   set(${var} "${listVar}" PARENT_SCOPE)
endfunction(pretend)

pretend(LIB_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src ${SRCS})
pretend(LIB_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME} ${HDRS})

####################
## Build the library
add_library(
  ${CMAKE_PROJECT_NAME} STATIC
  ${LIB_HDRS}
  ${LIB_SRCS}
)

############################
## Install it and the header
install(
  TARGETS ${CMAKE_PROJECT_NAME}
  EXPORT ${CMAKE_PROJECT_NAME}-export
  DESTINATION lib
  INCLUDES DESTINATION include
)

install(
  FILES ${LIB_HDRS}
  DESTINATION include/${CMAKE_PROJECT_NAME}
)

if(UNIX)
  set(CONFIG_DIR lib/${CMAKE_PROJECT_NAME}/cmake)
else()
  set(CONFIG_DIR CMake)
endif()

##########################################
## Generate and install CMake config files
include(CMakePackageConfigHelpers)

configure_package_config_file(
  ${CMAKE_PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${CONFIG_DIR}
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
  VERSION 1.0
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
  DESTINATION ${CONFIG_DIR}
)

install(
  EXPORT ${CMAKE_PROJECT_NAME}-export
  DESTINATION lib/${CMAKE_PROJECT_NAME}/cmake
)

######################################
## set compiler features
# comment in needed compiler features
set(NEEDED_FEATURES
#  cxx_template_template_parameters
#  cxx_alias_templates
#  cxx_alignas
#  cxx_alignof
#  cxx_attributes
#  cxx_auto_type
#  cxx_constexpr
#  cxx_decltype
#  cxx_decltype_incomplete_return_types
#  cxx_default_function_template_args
#  cxx_defaulted_functions
#  cxx_defaulted_move_initializers
#  cxx_delegating_constructors
#  cxx_deleted_functions
#  cxx_enum_forward_declarations
#  cxx_explicit_conversions
#  cxx_extended_friend_declarations
#  cxx_extern_templates
#  cxx_final
#  cxx_func_identifier
#  cxx_generalized_initializers
#  cxx_inheriting_constructors
#  cxx_inline_namespaces
#  cxx_lambdas
#  cxx_local_type_template_args
#  cxx_long_long_type
#  cxx_noexcept
#  cxx_nonstatic_member_init
#  cxx_nullptr
#  cxx_override
#  cxx_range_for
#  cxx_raw_string_literals
#  cxx_reference_qualified_functions
#  cxx_right_angle_brackets
#  cxx_rvalue_references
#  cxx_sizeof_member
#  cxx_static_assert
  cxx_strong_enums
#  cxx_thread_local
#  cxx_trailing_return_types
#  cxx_unicode_literals
#  cxx_uniform_initialization
#  cxx_unrestricted_unions
#  cxx_user_literals
#  cxx_variadic_macros
#  cxx_variadic_templates
#  cxx_attribute_deprecated
#  cxx_binary_literals
#  cxx_contextual_conversions
#  cxx_decltype_auto
#  cxx_digit_separators
#  cxx_generic_lambdas
#  cxx_lambda_init_captures
#  cxx_return_type_deduction
)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE ${NEEDED_FEATURES})
