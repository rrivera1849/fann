#include "floatfann.h"

int main( int argc, char** argv )
{
  unsigned int* layers = malloc (sizeof (unsigned int) * 3);
  layers[0] = 2;
  layers[1] = 2;
  layers[2] = 2;

	struct fann *ann = fann_create_standard_array(3, layers);

  printf ("Before Normalize!\n");
  fann_randomize_weights_normalize_variance(ann);
  printf ("After Normalize!\n");

  printf ("Connection rate %f\n", fann_get_connection_rate (ann));

  struct fann_connection *connections = malloc (sizeof (struct fann_connection) * fann_get_total_connections (ann));
  fann_get_connection_array (ann, connections);

  for (int i = 0; i < fann_get_total_connections (ann); i++)
  {
    printf ("From %d To %d Weight %f\n", 
            connections[i].from_neuron, connections[i].to_neuron, 
            connections[i].weight);
  }

  free (connections);

	fann_destroy(ann);
	return 0;
}
