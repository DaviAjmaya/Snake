typedef struct _point
{
	_point()
	{
	}
	_point(double x, double y)
	{
	 X = x;
	 Y = y;
	}
	double X;
	double Y;
}Point;

typedef struct _size
{
	double Width;
	double Height;
}Size;

typedef _point Vector;



