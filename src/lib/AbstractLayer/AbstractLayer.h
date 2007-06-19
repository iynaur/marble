//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2004-2007 Torsten Rahn  <tackat@kde.org>"
// Copyright 2007      Inge Wallin   <ingwa@kde.org>"
// Copyright 2007      Andrew Manson <g.real.ate@gmail.com>"
//

#ifndef ABSTRACTLAYER_H
#define ABSTRACTLAYER_H

#include "Quaternion.h"
#include "AbstractLayerContainer.h"
#include <QtCore/QObject>
#include <QtCore/QSize>


/*! \brief This class is to represent the base class for each of the
 * levels in the rendering of the Marble display.
 * 
 * It will contain all info nessary to draw a layer.
 * */
class AbstractLayer: public QObject
{
    Q_OBJECT

    public:
        //!an empty constructor, so far.
        AbstractLayer(QObject * parent=0);

        /*! \brief get screen pixel position
         * 
         * Method to simplify the retrieval of the screen pixel position 
         * from a longditude and latitude.
         * \param _long the longitude of the point we want to find
         * \param _lat the latitude of the point we want to find 
         * \param invRotAxis inversion of the Quaternion status of the
         * globe
         * \param screenSize size of the screen
         * \param xOut where the x value of the point will be stored
         * \param yOut where the y value of the point will be stored
         * \param radius FIXME: add roll of the radius in this comment
         * \return boolean value as to whether the point is visible on 
         * screen
         **/
        bool getPixelPosFromGeoPoint(double _lon, double _lat, 
                                     QSize screenSize, 
                                     Quaternion invRotAxis, 
                                     int radius, int &xOut, 
                                     int &yOut);

         /*!\brief get screen pixel position
          * 
          * Method to simplify the retreval of the screen pixel position
          * from a Quaternion.
          * \param position the position of the point we want to find
          * \param invRotAxis inversion of the Quaternion status of the
          * globe
          * \param screenSize size of the screen
          * \param xOut where the x value of the point will be stored
          * \param yOut where the y value of the point will be sotred
          * \param radius FIXME: add roll of the radius in this comment
          * \return boolean value as to whether the point is visable on 
          * screen
          **/ 
        bool getPixelPosFromGeoPoint(Quaternion position, 
                                     QSize screenSize, 
                                     Quaternion invRotAxis, 
                                     int radius, int &xOut, 
                                     int &yOut);
    private:
        /*!
         * AbstractLayerData container with all the nessary data for
         * this layer.
         */
        AbstractLayerContainer *layerData;
};
#endif //ABSTRACTLAYER_H

