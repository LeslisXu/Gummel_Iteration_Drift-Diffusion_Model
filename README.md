# Gummel_Iteration_Drift-Diffusion_Model
使用了Gummel迭代方法求解Drift-Diffusion-Model，其中对于电子载流子电流密度J_n、空穴载流子电流密度J_p使用了Scharfetter-gummel discretization数值离散格式处理。

## Drift-Diffusion Model

- (a) $-\lambda^2 \Delta \psi+e^\psi u-e^{-\psi} v-C(x)=0$,
    
- (b) $- \text{div} J_n+R=0$,

- (c) $J_n=\mu_n e^\psi \nabla u$,

- (d) $\text{div} J_p+R=0$,

- (e) $J_p=-\mu_p e^{-\psi} \nabla v$

$$
-\nabla \cdot J_n+R\left( x \right) =0
$$

使用论Scharfetter-Gummel数值离散格式，将电子电流密度$J_n$离散为以下格式：

$$
J_{n+\frac{1}{2}}=\frac{1}{h_i}\left[ B\left( \psi _{i+1}-\psi _i \right) n_{i+1}-B\left( \psi _i-\psi _{i+1} \right) n_i \right] ,
$$
$$
J_{n-\frac{1}{2}}=\frac{1}{h_i}\left[ B\left( \psi _i-\psi _{i-1} \right) n_i-B\left( \psi _{i-1}-\psi _i \right) n_{i-1} \right] .
$$

其中 $B(x)=\frac{x}{e^x-1}$ 是Bernoulli函数。

方程的数值离散格式为
$$
-\frac{J_{n+\frac{1}{2}}-J_{n-\frac{1}{2}}}{h_i}+R\left( x \right) =0.
$$
