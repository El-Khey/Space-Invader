#ifndef IMAGE_H
#define IMAGE_H

#include "../position/position.h"
#include "../dimension/dimension.h"

#define MAX_CHARACTERS 250

/**
 * @struct Image
 * @brief Représente une image avec sa dimension, sa position, son chemin d'accès et son image MLV.
 */
typedef struct
{
    Dimension dimension;       /**< La dimension de l'image */
    Position position;         /**< La position de l'image */
    char path[MAX_CHARACTERS]; /**< Le chemin d'accès de l'image */
    MLV_Image *image;          /**< L'image MLV */
} Image;

/**
 * @brief Charge une image à partir d'un chemin et la redimensionne aux dimensions données.
 *
 * @param path Le chemin vers l'image.
 * @param dimension Les dimensions pour redimensionner l'image.
 * @return Image* Un pointeur vers l'image chargée et redimensionnée.
 */
Image load_image(char *path, Dimension dimension);

/**
 * @brief Effectue un miroir vertical de l'image.
 *
 * @param image L'image à miroiter.
 */
void vertical_image_mirror(Image *image);

/**
 * @brief Vérifie si l'image a été chargée avec succès.
 *
 * @param image L'image à vérifier.
 * @param path Le chemin vers l'image.
 * @return int 1 si l'image a été chargée avec succès, 0 sinon.
 */
int is_image_loaded_successfully(MLV_Image *image, char *path);

/**
 * @brief Obtient les dimensions de l'image.
 *
 * @param image L'image dont on veut obtenir les dimensions.
 * @return Dimension Les dimensions de l'image.
 */
Dimension get_image_dimension(MLV_Image *image);

/**
 * @brief Définit la position de l'image.
 *
 * @param image L'image à positionner.
 * @param position La position à définir.
 */
void set_image_position(Image *image, Position position);

/**
 * @brief Définit les dimensions de l'image.
 *
 * @param image L'image à redimensionner.
 * @param dimension Les dimensions à définir.
 */
void set_image_dimension(Image *image, Dimension dimension);

/**
 * @brief Libère l'image de la mémoire.
 *
 * @param image L'image à libérer.
 */
void free_image(Image *image);

/**
 * @brief Dessine l'image.
 *
 * @param image L'image à dessiner.
 */
void draw_image(Image *image);

#endif /** IMAGE_H */