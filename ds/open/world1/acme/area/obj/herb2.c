inherit ITEM;
void create()
{
        set_name("�C�P������", ({ "seven star herb","herb" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","�b�o�����l�W���ۤC�I�����⪺�p�I�A�ݰ_�ӫD�`�㲴�C\n");
          set("unit","��");
          set("value",1);
        }
     setup();
}
