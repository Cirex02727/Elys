#pragma once

#include <memory>
#include "Elys/Renderer/Buffer.h"

namespace Elys {

	class VertexArray
	{
		public:
			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
			virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

			virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
			virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

			static Ref<VertexArray> Create();
	};
}
