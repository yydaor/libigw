
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "igw.h"
#include "callback.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

void gwBegin()
{
	/* Reset the active and hot ids. */
	g_gwContext.id_hot = 0;
	if (g_gwContext.mouse.button[GW_MOUSE_BUTTON_LEFT] == GW_BUTTON_STATE_UP)
		g_gwContext.id_active = 0;

	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT | GL_POLYGON_BIT);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_TEXTURE_1D);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glDisable(GL_SCISSOR_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	float w = g_gwContext.viewport.width;
	float h = g_gwContext.viewport.height;

	w = (w != 0 ? w : 1);
	h = (h != 0 ? h : 1);

	glTranslatef(-1, 1, 0);
	glScalef(2.0 / w, -2.0 / h, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void gwEnd()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glPopAttrib();
}

void gwPostRedisplay()
{
	glutPostRedisplay();
}

void gwDrawBox(GWfloat x, GWfloat y, GWfloat w, GWfloat h, GWcolor4f_t *col_a, GWcolor4f_t *col_b)
{
	if (col_a == NULL || col_b == NULL)
		return;

	glBegin(GL_QUADS);
		glColor4f(col_a->r, col_a->g, col_a->b, col_a->a);
		glVertex2f(x    , y);
		glVertex2f(x + w, y);
		glColor4f(col_b->r, col_b->g, col_b->b, col_b->a);
		glVertex2f(x + w, y + h);
		glVertex2f(x    , y + h);
	glEnd();
}

void gwDrawLine(GWfloat x0, GWfloat y0, GWfloat x1, GWfloat y1, GWcolor4f_t *col)
{
	if (col == NULL)
		return;

	glBegin(GL_LINES);
		glColor4f(col->r, col->g, col->b, col->a);
		glVertex2f(x0, y0);
		glVertex2f(x1, y1);
	glEnd();
}

void gwDrawText(GWfloat x, GWfloat y, GWcolor4f_t *col, const GWchar *str)
{
	if (col == NULL)
		return;

	glColor4f(col->r, col->g, col->b, col->a);
	glRasterPos2f(x, y);
	while(*str) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *str++);
	}
}

float gwTextLength(const char *str)
{
	return (float)glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)str);
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
