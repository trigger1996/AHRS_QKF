# AHRS_QKF

这份代码是基于https://github.com/hkbl1988/AHRS_EKF的代码改写而来的
对一些大变量做了裁剪，为了方便植入嵌入式里面，比如STM32
我自己做测试的时候收敛比原作者的慢，16000+多的数据，大概在2000的时候才收敛
