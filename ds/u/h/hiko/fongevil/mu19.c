inherit MOBROOM;
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
  "southdown" : __DIR__"mu20",
  "northwest" : __DIR__"mu15",
   ]) );
        set("chance",50);
        set("mob_amount",2);
        set("mob_object",({
  __DIR__"animal/monkey",
  }) );
set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 









