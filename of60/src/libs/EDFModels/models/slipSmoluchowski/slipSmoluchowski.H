/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 

\*---------------------------------------------------------------------------*/

#ifndef slipSmoluchowski_H
#define slipSmoluchowski_H

#include "EDFEquation.H"

namespace Foam
{
namespace EDFEquations
{
/*---------------------------------------------------------------------------*\
                           Class slipSmoluchowski Declaration
\*---------------------------------------------------------------------------*/

class slipSmoluchowski
:
    public EDFEquation
{
    // Private data

        //- Externally applied electric potential
        volScalarField phiE_;

        //- Electric force
        volVectorField zeroFe_;

        //- Solution controls for phiE and psi
          
            // Residuals treshold
            scalar phiEEqRes_;
            
            // Max number of iterations
            int maxIterPhiE_;
            
    // Private Member Functions

        //- Disallow default bitwise copy construct
        slipSmoluchowski(const slipSmoluchowski&);

        //- Disallow default bitwise assignment
        void operator=(const slipSmoluchowski&);
     
public:

    //- Runtime type information
    TypeName("slipSmoluchowski");

    // Constructors

        //- Construct from components
        slipSmoluchowski
        (
            const word& name,
            const surfaceScalarField& phi,
            const dictionary& dict
        );


    // Destructor

        virtual ~slipSmoluchowski()
        {}


    // Member Functions

        //- Return the electric force for the momentum equation
         virtual tmp<volVectorField> Fe() const;

        //- Update the electric force
        virtual void correct();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace EDFEquations
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
