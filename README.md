# circular-buffer
Header-only circular buffer implementation

## Running unit tests on Docker image

Make sure you pull the docker image from [here](https://hub.docker.com/repository/docker/naveenspace7/cpp-dev).

Once the docker image is pulled, navigate to the repository's parent directory and run the following command:

`$ sudo docker run -v $(pwd):/mnt cpp-dev make run_test`
