#include "buffer.h"

namespace sudo { namespace graphics { 

	Buffer::Buffer()
	{

	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(m_type, &m_id);
	}

	void Buffer::bind() const
	{
		glBindBuffer(m_type, m_id);
	}

	void Buffer::unbind() const
	{
		glBindBuffer(m_type, 0);
	}

} } 