#include "mystery_app.hpp"

using Mystery::MysteryApplication;

// entry point
int main() {
	const auto app = std::unique_ptr<MysteryApplication>(new MysteryApplication());
	app->Run();
}