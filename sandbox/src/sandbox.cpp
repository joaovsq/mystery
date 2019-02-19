#include "sandbox.hpp"

Sandbox::Sandbox()
{
}


Sandbox::~Sandbox()
{
}

// TODO: Move this main function to the Engine in a entry_point.hpp file
int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}
