namespace myengine
{
	struct Environment
	{
		public:
			Environment();
			float getDeltaTime();
			void tick();
		private:
			float dt;
			float last;
	};
}