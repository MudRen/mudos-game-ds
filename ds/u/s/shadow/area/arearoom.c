/**
 * Shadow's area room [v.1]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�Q���D�b"NOR);
	set("long",@LONG
�@�Ӳ��`��T���X�j�]�A���e���\�m�ۤ@�ӥj�몺����A��W�E
�۵ۤ@�i�Ŷ�����ֱ��b�A�J�Ӥ@�ݭ�ӳ��O�@�ǭx���P�ԨƧ𨾤�
�p�A�ݵ۬ݵۤ������A�Ⲥ���Q���Ъ����~�j���A�]���T���Q������
�ԦʳӤߧ�C�b�����k�ⰼ���C�F���Ъ���çL�u�Q�K�K�M�v�A�ӭ�
�ҬO��H�@�צʪ��n��A�@���l�˧����S���Z����աA���D�u�O�Y�F
�����K�F�ߧ_�h�d�U���i�b���y���C
LONG
	);
	set("light",1);
	set("exits",([
		"north": "/u/s/shadow/workroom",
		"east": __DIR__"a1",
	]));

	/**
	 * �]�p���~�P�ͪ�
	 */	 
	set("item_desc",([
		"���b": "		
"HIG"�ثe���b�i�椤���ϰ즳:\n"NOR"
    1. ����
    2. ���@��\n
"HIW"�H��Q�n�i�檺�ϰ즳:\n"NOR"
    1. �j�ԧ�\n"])); 
	
	setup();

}
