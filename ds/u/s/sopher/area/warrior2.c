
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"�W�s�x�βĤ@����"NOR);
        set ("long", @LONG
�Ө�F�Ĥ@�����A�|�P�ܪ����`���w�R�A�A�Pı��
��������A���O�Ů𤤫o�j���@�ѥO�H���H�ݮ�����
���I�A�V�e���h�A���@���p�U�l(book)..�A�i�h�ݬ�
�A���ӹ惡�঳��`�h���{�ѡC
LONG);  
        set("no_fight",1);
        set("no_spells",1);
        set("no_magic",1);
        set("exits", ([
        "west": __DIR__"warrior3",
        "east": __DIR__"warrior1",
         ]) );
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "book": "�w����{�W�s�Ĥ@����!
        �������������T�M�ΡA���O���G
        1.���s�M��...�Ϊ�:��Դ������洵�S;
        2.�p�s�M��...�Ϊ�:�𴵿�;
        3.�B�s�M��...�Ϊ�:��Դ�;
        ���x���Ωe�U�Ч�ڭ̳B�z�A�L�W��a!
        �H�U�O�����M�Ϊ������G
        1.���s�M��:�C�Φ@��400��C�h�A���F���s
        �T�ö����Ϊ����M�ݧL�Φ@��20��C�h�׭^
        �A�D�n���Ȭ��Ԩƪ��ɧU�P�i��C
        2.�p�s�M��:�C�Φ@��300��g�Ԥh�A�[�W�p
        �s�T�íx�`�@315�ӳ��@�ΡA��D�n���Ȭ�
        �ĤH�e�u���}�a�P�R���C
        3.�B�s�M��:�C�Φ@��100���]�k�ϡC�ѩ�S
        ���Ԥh�Ϊ��ɧU�A�]���D�n���Ȭ��Խu���
        ���ɧU�����P���ͪ��v���C
                             end", ]) );
        setup();
        replace_program(ROOM);
}
