#include <command.h>
#include <path.h>
inherit ROOM;
void create()
{
        set("short", "�T��");
        set("long", @LONG
�b�T�Ӫ��ӱ�f�\�ۤ@�i�P�l�A�g�D�G�u��פ��A�Ȱ��}��v�A�ݨ�
���h�٦b��פ��A�k������W�}�F�@�Ӥj�}�A�a�O���O�|�|�}�}�A�̡u��
�Ѽӡv���]�ȡA��|����p��?
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
"down" : __DIR__"inn_2f",
//"up" : "/u/a/alickyuen/open/christmas/chris1",
        ]));
        set("item_desc",([      
        "�j�}" : "�@�Ӷ}�b����W���j�}�A�i�ݨ��W���ɹL�����H�s�C\n���U�h(jump into hole)�i��|�����˳�!\n",
        "hole" : "�@�Ӷ}�b����W���j�}�A�i�ݨ��W���ɹL�����H�s�C\n���U�h(jump into hole)�i��|�����˳�!\n",
        ])      );
        set("light",1);
        set("no_clean_up", 0);
         set("objects", ([ /* sizeof() == 1 */
                "/open/lottery/erika" : 1,
//                    "/open/world1/tmr/game/2008_ghost/board" : 1,
          ]));

        setup();
} 
/*
void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file;
 me=this_player();
 if(!arg) return 0;
 if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
 if(sscanf(arg, "into %s", arg)==1)
 {
  if(arg=="hole" || arg=="�j�}")
  {
   if(me->query_temp("ride"))
   {
        write("���M�A�@�N��, �i�O�A���y�M�o���@�N..\n");
        return 1;
   }
   if(me->query_temp("killer"))
  {
    write("�A���F�H�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("�A�����F���a�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if((sscanf(file,"/open/world2/%s",buffer1)!=1 && sscanf(file,"/open/always/%s",buffer1)!=1 )
     || inv[i]->query_max_encumbrance() > 0)
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   tell_room(environment(me),me->name()+"�`�l�F�@�f��, �ĤO����������j�}���F�X�h�C\n",({ me }));
   message("system", "$N��U�@�Ǧh�l�����~, �`�l�F�@�f��, �ĤO����������j�}���F�X�h�C\n\n",me);

 me->move(NOW"anfernee/start/pastroom");
 me->set("startroom",NOW"anfernee/start/pastroom");
 me->save();
 message("system", "��M�@�}�Ŷ����ᦱ.. �A�S�^��F���x���a��C\n\n",me);
 tell_room(environment(me),me->name()+"��M�q�γ��W���}�}�^�F�U�ӡC\n",({ me }));
 me->start_busy(1);
   return 1;
  } 
 }
 else return 0;
}
*/

