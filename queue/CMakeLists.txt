file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h

add_executable(${queue} ${srcs} ${hdrs})

target_link_libraries(${queue} ${libqueue}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}

