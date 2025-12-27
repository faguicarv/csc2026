// CSC Latin America 2026 - Particle Tests
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "Particle.hpp"

using namespace csc2026;
using Catch::Approx;

TEST_CASE("Particle default constructor", "[particle]") {
    Particle p;
    REQUIRE(p.px() == 0.0);
    REQUIRE(p.py() == 0.0);
    REQUIRE(p.pz() == 0.0);
    REQUIRE(p.mass() == 0.0);
}

TEST_CASE("Particle parameterized constructor", "[particle]") {
    Particle p(1.0, 2.0, 3.0, 0.139);
    REQUIRE(p.px() == 1.0);
    REQUIRE(p.py() == 2.0);
    REQUIRE(p.pz() == 3.0);
    REQUIRE(p.mass() == 0.139);
}

TEST_CASE("Particle pT calculation", "[particle]") {
    Particle p(3.0, 4.0, 0.0, 0.0);
    REQUIRE(p.pt() == Approx(5.0));
}

TEST_CASE("Particle momentum calculation", "[particle]") {
    Particle p(1.0, 2.0, 2.0, 0.0);
    REQUIRE(p.p() == Approx(3.0));
}

TEST_CASE("Particle energy calculation", "[particle]") {
    // E = sqrt(p^2 + m^2)
    Particle p(3.0, 4.0, 0.0, 0.0);  // p = 5, m = 0 -> E = 5
    REQUIRE(p.energy() == Approx(5.0));
    
    Particle p2(3.0, 4.0, 0.0, 12.0);  // p = 5, m = 12 -> E = 13
    REQUIRE(p2.energy() == Approx(13.0));
}

TEST_CASE("Particle phi calculation", "[particle]") {
    Particle p1(1.0, 0.0, 0.0, 0.0);
    REQUIRE(p1.phi() == Approx(0.0));
    
    Particle p2(0.0, 1.0, 0.0, 0.0);
    REQUIRE(p2.phi() == Approx(M_PI / 2.0));
    
    Particle p3(-1.0, 0.0, 0.0, 0.0);
    REQUIRE(p3.phi() == Approx(M_PI));
}

TEST_CASE("Particle addition", "[particle]") {
    Particle p1(1.0, 0.0, 0.0, 0.0);
    Particle p2(-1.0, 0.0, 0.0, 0.0);
    
    Particle sum = p1 + p2;
    REQUIRE(sum.px() == Approx(0.0).margin(1e-10));
    REQUIRE(sum.py() == Approx(0.0).margin(1e-10));
    REQUIRE(sum.pz() == Approx(0.0).margin(1e-10));
}

TEST_CASE("Invariant mass of two particles", "[particle]") {
    // Two photons (m=0) going in opposite directions
    // E_total = 2, p_total = 0 -> m_inv = 2
    Particle p1(1.0, 0.0, 0.0, 0.0);
    Particle p2(-1.0, 0.0, 0.0, 0.0);
    
    double mInv = invariantMass(p1, p2);
    REQUIRE(mInv == Approx(2.0));
}

TEST_CASE("Z boson mass reconstruction", "[particle][physics]") {
    // Two electrons from Z decay (simplified)
    // Z mass ~ 91.2 GeV
    double mZ = 91.2;
    double pT = 45.0;
    
    // Electron 1: going +z
    Particle e1(pT, 0.0, pT, 0.000511);
    // Electron 2: going -z
    Particle e2(-pT, 0.0, -pT, 0.000511);
    
    double mInv = invariantMass(e1, e2);
    // Should be approximately 2 * sqrt(2) * pT for back-to-back
    REQUIRE(mInv > 100.0);  // Just check it's reasonable
}
