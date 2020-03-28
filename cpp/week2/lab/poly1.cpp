#include <stdio.h>
#include <stdlib.h>

typedef struct Monomial {
	int coeff;
	int exp;
	struct Monomial *next;
} Mono;

typedef struct Polynomial {
	Mono *first;
	Mono *last;
} Poly;

// creates a Mono on the heap and returns a pointer to it
Mono *new_mono(int c, int k) {
	Mono* mono = malloc(sizeof(Mono));
	if (!mono) return NULL;
	mono->coeff = c;
	mono->exp = k;
	mono->next = NULL;
	return mono;
}

Poly *new_poly() {
	Poly *poly = malloc(sizeof(Poly));
	if(!poly) return NULL;
	poly->first =	poly->last = NULL;
	return poly;
}

void free_poly(Poly *p) {
	if (p == NULL) return;
	Mono *m1 = p->first;
	while (m1 != NULL) {
		Mono *m2 = m1->next;
		free(m1);
		m1 = m2;
	}
	free(p);
}

void append_mono(Poly *p, Mono *m) {
	if (p->first == NULL) {
		p->first = p->last = m;	
	} else {
		p->last->next=m;
		p->last = p->last->next;
	}
}

Poly *read_poly() {
	Poly *poly = new_poly();
	int c, k;
	do {
		scanf("%d %d", &c, &k);
		if (c != 0) {
			append_mono(poly, new_mono(c, k));
		}
	} while (k > 0);

	return poly;
}

void print_poly(Poly *p) {
	if (!p || !p->first) {
		printf("Empty polynomial.\n");
		return;
	} else {
		Mono *m = p->first;
		while (m != NULL) {
			int c = m->coeff;
			int k = m->exp;
			if (m != p->first && c > 0) printf(" + ");
			if (c < 0) printf(" - ");
			if (c*c != 1 || k == 0)
				printf("%d", (c > 0 ? c : -c));
			if (k > 0) printf("x^%d", k);
			m = m->next;
		}
		printf("\n");
	}
}

Poly *add_poly(Poly *p1, Poly *p2) {
	Poly *p = new_poly();
	Mono *m1 = p1->first;
	Mono *m2 = p2->first;

	while (m1 && m2) {
		if (m1->exp == m2->exp) {
			int c = m1->coeff + m2->coeff;
			append_mono(p, new_mono(c, m1->exp));
			m1 = m1->next;
			m2 = m2->next;
		} else if (m1->exp > m2->exp) {
			append_mono(p, new_mono(m1->coeff, m1->exp));
			m1 = m1->next;
		} else {
			append_mono(p, new_mono(m2->coeff, m2->exp));
			m2 = m2->next;
		}
	}

	while (m1) {
		append_mono(p, new_mono(m1->coeff, m1->exp));
		m1 = m1->next;
	}

	while (m2) {
		append_mono(p, new_mono(m2->coeff, m2->exp));
		m2 = m2->next;
	}

	return p;
}

int main(void) {
	Poly *p1 = read_poly();
	Poly *p2 = read_poly();
	print_poly(p1);
	print_poly(p2);
	Poly *res = add_poly(p1, p2);
	print_poly(res);
	free_poly(p1);
	free_poly(p2);
	free_poly(res);
	return 0;
}
