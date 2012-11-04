#ifndef I_RENDERER
#define I_RENDERER

/**
 An interface that defines all the necessary render functions that must be supported in order to
 render Roosevelt.
*/
class IRenderer {
public:
	/**
     Virtaul destructor! Hurray for not having memory leaks.
    */
	virtual ~IRenderer() {}

	/**
	 Clear to the background color.
	*/
	virtual void Clear() = 0;

	/**
	 Draw a rectangle. The rectangle can represent anything! Even a monkey!

	 \param x top left position of the rectangle
	 \param y top left position of the rectangle
	 \param width width of the rectangle.
	 \param height height of the rectangle.
	 \param r 0-255 red color
	 \param g 0-255 green color
	 \param b 0-255 blue color
	*/
	virtual void DrawRectangle(double x, double y, double width, double height, int r, int g, int b) = 0;

	/**
	 We're done rendering. Present the rendered image to the sreen.
	*/
	virtual void Present() = 0;
};

#endif // I_RENDERER