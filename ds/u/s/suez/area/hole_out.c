
inherit ROOM;

void create()
{
 set("short","�}��");
        set("long",@LONG
�A�@���i�o�̡A�N�Q�|���������g�F�����A�g���u�Ӯg�{�{�o�G����
���z�X�@�Ѹ޲����𮧡C�}�B�n���^���b�A����L�١A�g�۪�����A���t
�����D�A�Aı�o�n����@�ɹj���F�C�b�A�v���[�֪��I�l�Τ߸����A�A�O
�_�٭n�A���e���O�S
LONG
        );

         set("exits", ([
         "north": __DIR__"hole_1",
       "out": __DIR__"hotel_room4",

         ]));
  
        
        setup();
        replace_program(ROOM);

 }