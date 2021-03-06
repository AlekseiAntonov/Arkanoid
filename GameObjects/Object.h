#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using sf::Sprite;
using sf::Texture;
using sf::FloatRect;
using sf::Vector2f;
using sf::IntRect;
using sf::RenderWindow;
using std::string;
/*!
 * \class Object
 * \brief The class of all game objects.
 *
 * \details Consists of Sprite and Texture to operate with game objects. Used to group all
 * of the objects and optimize their  comunication.
 */

class Object
{
private:
	Sprite object; ///< Drawable representation of a texture, with its own transformations, color, etc.
    Texture texture;///< Texture of object.

public:
    /*!
     * \brief Gets the sizes of the object.
     * @return sizes of the object.
     */
    FloatRect get_dimensions() const;
	/*!
	 * \brief Changes the shape of the object.
	 * @param new_dimensions new shape.
	 */
	void change_size(IntRect new_dimensions);
	/*!
	 * \brief Check is object in touch with another objects.
	 * @param other_object Another Object.
	 * @return Is they are in touch.
	 */
	bool is_touch( const Object& other_object) const;
    /*!
     * \brief Sets the object position.
     * @param x New abscissa.
     * @param y New ordinate.
     */
    virtual void set_position(float x, float y);
    /*!
     * \brief Gets the position of the upper left corner.
     * @return Position of the upper left corner.
     */
	Vector2f get_position();
	/*!
	 * \brief Draws the object.
	 * @param window The current window.
	 */
    virtual void draw(RenderWindow& window) const;
    /*!
     * \brief Sets the texture.
     *
     * \details There is an image from the image path. The func picks it for texture to object.
     * @param image_path The path to the image.
     */
	void set_texture(const string& image_path);
};

