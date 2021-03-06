#include "internal_caps.h"
#include <unistd.h>
#include <termcap.h>

static int	internal_caps__putc(int c)
{
	t_internal_context	*context;

	caps__get_context(&context);
	return (write(context->fd, &c, 1));
}

extern int	caps__print(const char *s, const size_t line_count)
{
	if (!s)
	{
		tputs("(Null)", 1, &internal_caps__putc);
		return (0);
	}
	return (tputs(s, line_count, &internal_caps__putc));
}
