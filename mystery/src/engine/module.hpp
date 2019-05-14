#pragma once

namespace Mystery
{
	/**
	 * @brief A interface used for defining engine modules.
	 */
	class Module
	{
	public:
		/**
		 * @brief Represents when a module will call <seealso cref="Module#Update()"/> in the update loop.
		 */
		enum class Stage
		{
			Always, Pre, Normal, Post, Render
		};

		virtual ~Module() = default;

		/**
		 * The update function for the module.
		 */
		virtual void Update() = 0;
	};

}
