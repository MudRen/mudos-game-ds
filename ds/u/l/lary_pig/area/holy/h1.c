#include "/u/l/lary/area/holy/path.h"
inherit ROOM;

void create()
{
        set("short", "�t��J�f");
        set("long", @LONG
���j���ǻ��A�����O�q���Ҧb�F�۶ǡA�j�Ѫ��t�줤�A���~�F�@
�s�֦��j�j�O�q�������H���A�H���A�����L�ƪ��i�h�e�ӱ��I�A�o��
�@�h���^�A�Ӳ{�b�A�b�A���e�A�N�O���ǻ����t�쪺�j���A�ݵۨ���
�觹���Q������Ţ�n���t��A �A�u�����Ӥ����|�B�V�e...
LONG
        );

        set("exits", ([
 "west" : HOLY+"h2",
        ]) );
        set("light",1);
        setup();
}
