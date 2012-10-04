link_directories(${CSEngine_SOURCE_DIR}/src)
add_executable (out ${CSEngine_SOURCE_DIR}/src/test.cc)

target_link_libraries(out engine gameobject world camera emitter
			  input physics spritesheet graphics window
			  audio image configfile ${OPENGL_LIBRARIES}
			  ${SDL_LIBRARY} ${FREEIMAGEPLUS_LIBRARY})
