@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_874_grp, bank_026
	.equ	seq_874_pri, 127
	.equ	seq_874_rev, 0
	.equ	seq_874_mvl, 127
	.equ	seq_874_key, 0

	.section .rodata
	.global	seq_874
	.align	2

@*********************** Track 01 ***********************@

seq_874_0:
	.byte	KEYSH , seq_874_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 17
	.byte		VOL   , 127*seq_874_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N10   , As3 , v088
	.byte	W09
	.byte		        Gs3 
	.byte	W09
	.byte		        Fs3 
	.byte	W09
	.byte		        Fn3 
	.byte	W10
	.byte		VOICE , 3
	.byte	W04
	.byte		N24   , Gn2 , v120
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v+0
	.byte	W16
	.byte	FINE

@******************************************************@

	.align	2

seq_874:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_874_pri	@ Priority
	.byte	seq_874_rev	@ Reverb

	.word	seq_874_grp

	.word	seq_874_0

	.end