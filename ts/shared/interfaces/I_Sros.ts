export interface I_Sros<Num_t> {
	/** add */
	a(x: Num_t, ...y: Num_t[]): Num_t;
	/** subtract */
	s(x: Num_t, y: Num_t): Num_t;
	/** multiply */
	m(x: Num_t, ...y: Num_t[]): Num_t;
	/** divide */
	d(x: Num_t, y: Num_t): Num_t;
	/** power */
	p(x: Num_t, y: Num_t): Num_t;
}