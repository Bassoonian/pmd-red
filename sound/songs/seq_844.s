@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_844_grp, bank_026
	.equ	seq_844_pri, 127
	.equ	seq_844_rev, 0
	.equ	seq_844_mvl, 127
	.equ	seq_844_key, 0

	.section .rodata
	.global	seq_844
	.align	2

@*********************** Track 01 ***********************@

seq_844_0:
	.byte	KEYSH , seq_844_key+0
	.byte	TEMPO , 160/2
	.byte		VOICE , 3
	.byte	W01
	.byte		VOL   , 120*seq_844_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn2 , v120
	.byte	W04
	.byte		N06   , Fn2 
	.byte	W10
	.byte		N04   , Bn2 
	.byte	W04
	.byte		N06   , Fn2 
	.byte	W10
	.byte		VOICE , 15
	.byte		N12   , An1 , v127
	.byte		N24   , Bn1 
	.byte	W13
	.byte		N10   , An1 , v092
	.byte	W11
	.byte		N06   , An1 , v060
	.byte	W07
	.byte		        An1 , v032
	.byte	W07
	.byte		N24   , An1 , v020
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

seq_844:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_844_pri	@ Priority
	.byte	seq_844_rev	@ Reverb

	.word	seq_844_grp

	.word	seq_844_0

	.end