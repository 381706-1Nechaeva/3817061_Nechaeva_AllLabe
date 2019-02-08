cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllLabe) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(vector vector) #Переменная с именем библиотеки
set(libvector libvector)
set(vectorTest vectorTest)

set(libthrows libthrows)

set(libstack libstack)
set(stackTest stackTest)
set(stack stack)

set(libqueue libqueue)
set(queueTest queueTest)
set(queue queue)

#set(liblist liblist)
#set(listTest listTest)
#set(list list)

#set(libpostfix libpostfix)
#set(postfixTest postfixTest)
#set(postfix postfix)

#set(libmultistack libmultistack)
#set(multistackTest multistackTest)
#set(multistack multistack)

#set(libarrlist libarrlist)
#set(arrlistTest arrlistTest)
#set(arrlist arrlist)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libvector ${CMAKE_CURRENT_SOURCE_DIR}/libstack ${CMAKE_CURRENT_SOURCE_DIR}/libqueue ${CMAKE_CURRENT_SOURCE_DIR}/libthrows
#${CMAKE_CURRENT_SOURCE_DIR}/libarrlist ${CMAKE_CURRENT_SOURCE_DIR}/liblist ${CMAKE_CURRENT_SOURCE_DIR}/libmultistack ${CMAKE_CURRENT_SOURCE_DIR}/libpostfix 
${CMAKE_CURRENT_SOURCE_DIR}/gtest)


add_subdirectory(vector)
add_subdirectory(libvector)
add_subdirectory(vectorTest)

#add_subdirectory(postfix)
#add_subdirectory(libpostfix)
#add_subdirectory(postfixTest)

add_subdirectory(stack)
add_subdirectory(libstack)
add_subdirectory(stackTest)

add_subdirectory(queue)
add_subdirectory(libqueue)
add_subdirectory(queueTest)

add_subdirectory(libthrows)

#add_subdirectory(list)
#add_subdirectory(liblist)
#add_subdirectory(listTest)

#add_subdirectory(multistack)
#add_subdirectory(libmultistack)
#add_subdirectory(multistackTest)

#add_subdirectory(arrlist)
#add_subdirectory(libarrlist)
#add_subdirectory(arrlistTest)

add_subdirectory(gtest)


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(Lift_lib) #Собираем проект в поддиректории lib1
