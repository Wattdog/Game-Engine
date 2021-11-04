#include <GL/glew.h>

#include <vector>
#include <memory>

namespace renderer
{
	struct VertexBuffer;

	struct VertexArray
	{
		public:
			VertexArray();
			void setBuffer(int location, std::shared_ptr<VertexBuffer> buffer);
			int getVertCount();
			GLuint getId();
		private:
			GLuint id;
			std::vector<std::shared_ptr<VertexBuffer> > buffers;
			int vertCount;
			bool dirty;
	};
}