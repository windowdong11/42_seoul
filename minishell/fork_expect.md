parent : 자식 A pid
	// child A 생성 - 1 (2 (3 생성))
parent : 자식 B pid
parent : 자식 C pid


// A
CHILD A
	// child B 생성 - 2 (3생성)
parent: 자식 B pid
	// child C 생성 - 
parent: 자식 C pid

// B
CHILD 2
	// child C 생성 - 4 ()

// C
CHILD 3