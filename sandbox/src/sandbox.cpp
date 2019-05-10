#include "sandbox.hpp"

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

// TODO: Move this main function to the Engine in a entry_point.hpp file
int main() {
	auto sandbox = std::unique_ptr<Sandbox>(new Sandbox());
	sandbox->Run();
}
