

#include "Orchestrator.hpp"

void init(Core::Orchestrator &data)
{
  //registering
  //adding data
}

/*   EXEmple systeme
void logging_system ( registry & r ) {
  auto const & positions = r . get_components < component :: position >() ;
  auto const & velocities = r . get_components < component :: velocity >() ;
  for ( size_t i = 0; i < positions . size () && i < velocities . size () ; ++ i ) {
    auto const & pos = positions [ i ];
    auto const & vel = velocities [ i ];
    if ( pos && vel ) {
      std :: cerr << i << " : Position = { " << pos . value () . x << " , " << pos . value
	() . y << " } , Velocity = { " << vel . value () . vx << " , " << vel . value () .
	vy << " } " << std :: endl ;
    }
  }
  }*/


int main(int argc, char *argv[])
{
  Core::Orchestrator data;

  init(data);
  while (1) {
    // system call Proto:
    //  void SYS_NAME(Orchestrator &data); 

  }
  return 0;
}
