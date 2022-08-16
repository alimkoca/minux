ENTRY(load_kernel_86)

SECTIONS {
	. = 1M;

	.mbheader : {
		*(.mbheader)
	}

	.text : {
		*(.text)
	}

	.rodata ALIGN(4K) : {
		*(.rodata)
	}

	.data ALIGN(4K) : {
		*(.data)
	}

	.bss ALIGN(4K) : {
		*(COMMON)
		*(.bss)
	}
}
