#pragma once

#include "Elys/Renderer/Framebuffer.h"

namespace Elys {

	class OpenGLFramebuffer : public Framebuffer
	{
		public:
			OpenGLFramebuffer(const FramebufferSpacification& spec);
			virtual ~OpenGLFramebuffer();

			void Invalidate();

			virtual void Bind() override;
			virtual void Unbind() override;

			virtual uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; }

			virtual const FramebufferSpacification& GetSpecification() const override { return m_Specification; }

		private:
			uint32_t m_RendererID;
			uint32_t m_ColorAttachment, m_DepthAttachment;
			FramebufferSpacification m_Specification;
	};
}
