#Variables                                                                         
.RECIPEPREFIX = >                                                                  
                                                                                   
SHELL=bash                                                                         
MAKEFLAGS += --no-builtin-rules                                                    
                                                                                   
CXX = g++                                                                          
CFLAGS =-g                                                           
CFLAGS += `pkg-config --cflags --libs gstreamer-1.0`                               
                                                                                   
#Rules                                                                             
main: main.o                                                                                                                                 
> $(CXX) $(CFLAGS) -o main main.o 
                                                                                   
main.o: main.cpp listen.h                                                          
> $(CXX) $(CFLAGS) -c main.cpp                                                     
clean:
> rm main main.o                                                                                   
