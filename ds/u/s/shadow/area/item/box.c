inherit BOX;

void create()
{
	set_name("�����_�c", ({ "treasure box", "box" }));
	set("long", @LONG
    �@�ӷt���⪺�_�c�A���G���۬۷�[�����~�N�A�Ϲꪺ������K
�����T�ۡA�W�Y�����Y�w�g�������áA���O��T���]�p���M���A�L�p
�i�I�A�ݨӭY�L�k�M�o�_�c���_�͡A���ȥû��]�����D�o�_�c���s��
�õۦ���_���C

LONG
	);
	
	set("value", 1);
	set("unit", "��");
	set("no_get", 1);
	
	/* �]�w�̤j�e�q */
	set_max_encumbrance(999999); 
	set_max_capacity(10);
		
	/* �]�w�i�}���_�ͪ��ؿ�+�ɦW */
	set_keys(({__DIR__"key"})); 
		
	setup();
	
	/**
	 * set_cover(int)
	 * 2: �S�\�l
	 * 3: �\�l�O���}
	 * 4: �\�l�Q���W
	 * 5: �\�l�Q�}�a
	 */
	set_cover(4);

	/** 
	 * set_lock(int)
	 * 6: �S��
	 * 7: ��O�}��
	 * 8: ��O�W�ꪺ
	 * 9: ��Q�}�a
	 */	
	set_lock(8);
}
