# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY salesReport.c .
# Compile the C program
RUN gcc -o salesReport salesReport.c
# Set the command to run when the container starts
CMD ["./salesReport"]