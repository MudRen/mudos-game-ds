inherit ROOM;
void create()
{
    set("short", "�r�ɥj���_��");
        set("long", @LONG
    ��Ǫ��s�����°��q�A���o�̦b�դѮɤ]�O���t����C�s���W���p�}
����F�@�����o�O�A�ѩ�o�̪������G�j�F���֡A�ҥH�o�O�����K�Q�j��
�n�̤��w�A���W�������v�l�]�������n�̡A�M�Ӧb�s���W�Ԫ����v�l�n��
���y�@�˺��ۧA�A�@�ѳ��˴˪��Pı���W���Y�A�A���}�B�U���U�֤F�C

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_6",
	"north" : __DIR__"map_2_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

