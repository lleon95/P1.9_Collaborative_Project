import unittest
from ctypes import *
from ljmd import MDSYS_T

class LjmdPropagateParticleUnitTest(unittest.TestCase):
    def setUp(self):
        so_path = "lib/libljmd.so"
        self.ljmd = CDLL(so_path)

        self.mvesq = 2390.05736153349

        self.sys = MDSYS_T(natoms=1,
                           mass=1,
                           epsilon=0.5,
                           sigma=12,
                           rcut=16,
                           box=32,
                           nsteps=1,
                           dt=1)

        self.sys.rx = (c_double * 1)()
        self.sys.ry = (c_double * 1)()
        self.sys.rz = (c_double * 1)()
        self.sys.vx = (c_double * 1)()
        self.sys.vy = (c_double * 1)()
        self.sys.vz = (c_double * 1)()
        self.sys.fx = (c_double * 1)()
        self.sys.fy = (c_double * 1)()
        self.sys.fz = (c_double * 1)()

        """
        For every test, the position and velocity of the two particles
		are initialized to zero.
		Each test will reset some value to a new case
        """
		#Particle 1
        self.sys.rx[0] = 0 
        self.sys.ry[0] = 0
        self.sys.rz[0] = 0
        self.sys.vx[0] = 0
        self.sys.vy[0] = 0
        self.sys.vz[0] = 0

    def test_2_particle_inside_threshold_1(self):
        self.sys.fx[0] = 2*self.mvesq

        self.ljmd.propagate1(byref(self.sys))

        self.assertAlmostEqual(1, self.sys.rx[0], 7)
        self.assertAlmostEqual(0, self.sys.ry[0], 7)
        self.assertAlmostEqual(0, self.sys.rz[0], 7)
		
        self.assertAlmostEqual(1, self.sys.vx[0], 7)
        self.assertAlmostEqual(0, self.sys.vy[0], 7)
        self.assertAlmostEqual(0, self.sys.vz[0], 7)

    def test_2_particle_inside_threshold_2(self):
        self.sys.ry[0] = 12

        self.ljmd.force(byref(self.sys))
        self.assertAlmostEqual(0, self.sys.fx[0], 7)
        self.assertAlmostEqual(1, self.sys.fy[0], 7)
        self.assertAlmostEqual(0, self.sys.fz[0], 7)

    def test_2_particle_inside_threshold_3(self):
        self.sys.rz[0] = 12

        self.ljmd.force(byref(self.sys))
        self.assertAlmostEqual(0, self.sys.fx[0], 7)
        self.assertAlmostEqual(0, self.sys.fy[0], 7)
        self.assertAlmostEqual(1, self.sys.fz[0], 7)

    def test_2_particle_outside_threshold_1(self):
        self.sys.rx[0] = 16

        self.ljmd.force(byref(self.sys))
        self.assertAlmostEqual(0, self.sys.fx[0], 7)
        self.assertAlmostEqual(0, self.sys.fy[0], 7)
        self.assertAlmostEqual(0, self.sys.fz[0], 7)

    def test_2_particle_outside_threshold_2(self):
        self.sys.ry[0] = 16

        self.ljmd.force(byref(self.sys))
        self.assertAlmostEqual(0, self.sys.fx[0], 7)
        self.assertAlmostEqual(0, self.sys.fy[0], 7)
        self.assertAlmostEqual(0, self.sys.fz[0], 7)

    def test_2_particle_outside_threshold_3(self):
        self.sys.rz[0] = 16

        self.ljmd.force(byref(self.sys))
        self.assertAlmostEqual(0, self.sys.fx[0], 7)
        self.assertAlmostEqual(0, self.sys.fy[0], 7)
        self.assertAlmostEqual(0, self.sys.fz[0], 7)
