
inherit ROOM;

void create()
{
 set("short","�p���");
        set("long",@LONG
�@�����ª��p��ΡA�γ��u�ѤU�@�b�A����]�n�n���Y�A��B������
���j�������A�����������G�٦��ǼC��X�Ӫ�����C���Τ�h�|�B����
�A�Ѻغظ�H�ݨӡA�������D�H�j���w�g���b�@�W�F�I
LONG
        );
        set("exits", ([
         "out":"/open/world1/tmr/ghost-forest/forest9",
                  ]));
        set("objects",([
              __DIR__"npc/yen-eu" : 1,
              ]) );
                
        setup();

        replace_program(ROOM);

 }
