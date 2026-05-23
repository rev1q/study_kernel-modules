/**
 * サンプルカーネルモジュール
 * - モジュール作成の勉強
 *
 * 概要
 * - CPUコア上で、現在実行されているスレッド（task_struct）を取得する
 *
 * Create Date : 2026/05/22
 *
 * Created By : Revi
 */

/**
 * 出力フォーマットの定義
 */
#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__

/**
 * ヘッダの定義
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>	/* currentマクロ */

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sample module using current");
MODULE_AUTHOR("Revi");

static inline void sample_macro(void)
{
	pr_info("current : pid=%d, tgid=%d, comm=%s, mm=%px, state=%c\n",
			task_pid_nr(current),	/* スレッドID */
			task_tgid_nr(current),	/* プロセスID */
			current->comm,		/* プロセス（スレッド）名 */
			current->mm,		/* プロセス仮想アドレス空間のポインタ */
			current->__state);	/* プロセスの状態 */
}

static int __init macro_init(void)
{

	pr_info("Install Module\n");
	sample_macro();
	return 0;
}

static void __exit macro_exit(void)
{
	pr_info("Remove Module\n");
	sample_macro();
}

module_init(macro_init);
module_exit(macro_exit);
