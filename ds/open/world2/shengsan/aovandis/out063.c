// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�������O�͡A�èS��������}�o�C�A�ݨ����䪺����̦��G��
�ǥզ⪺�F��A�٦��I�G����C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out012",
	    "east" : __DIR__"out064",
            ]));
	set("item_desc",([	
	"�հ�" : "����̦��@���~���A�q�Ϊ��ݰ_�����ӬO�@���p�����Ͱ��C\n",
	])	);
	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}