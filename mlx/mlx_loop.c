/*
** mlx_loop.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Aug  2 18:58:11 2000 Charlie Root
** Last update Fri Sep 30 14:47:41 2005 Olivier Crouzet
*/


#include	"mlx_int.h"

extern int	(*(mlx_int_param_event[]))();


int		mlx_loop(t_xvar *xvar)
{
	XEvent		ev;
	t_win_list	*win;

	fprintf(stderr, "mlx loop cesi<<<\n");

	mlx_int_set_win_event_mask(xvar);
	xvar->do_flush = 0;
	while (42)
	{
		while (!xvar->loop_hook || XPending(xvar->display))
		{
			XNextEvent(xvar->display,&ev);
			win = xvar->win_list;
			while (win && (win->window!=ev.xany.window))
				win = win->next;
			if (win && ev.type < MLX_MAX_EVENT)
			{
				if (ev.type == ClientMessage && (Atom)ev.xclient.data.l[0] == xvar->wm_delete_window)
					XDestroyWindow(xvar->display, win->window);
				if (win->hooks[ev.type].hook)
					mlx_int_param_event[ev.type](xvar, &ev, win);
			}
		}
		xvar->loop_hook(xvar->loop_param);
	}
}
