inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�A��F��s�����O�L���A�o�̪K���Z�K���O�B�ѡA�۵M���;�
�D�`���k�A��W���ɦ����U�]�Ӷ]�h�A�ݨӤQ���r��A�o�̪�����
�u���A���A��}���h�R�R���y�C�䤤�C
LONG
        );
  
set("exits", ([
  "southdown" : __DIR__"mu21",
  "northup" : __DIR__"mu19",
  "eastdown" : __DIR__"mu22", 
]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 







