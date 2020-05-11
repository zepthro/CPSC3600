OUT=UDP

default:
	g++ *.cpp -Wall -g -o ${OUT} 
server:
	./${OUT} server
client:
	./${OUT} client 5000
clean:
	rm -f ${OUT}