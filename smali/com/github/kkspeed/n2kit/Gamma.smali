.class public Lcom/github/kkspeed/n2kit/Gamma;
.super Ljava/lang/Object;
.source "Gamma.java"


# static fields
.field private static final TAG:Ljava/lang/String; = "com.github.kkspeed.n2kit"


# direct methods
.method static constructor <clinit>()V
    .locals 1

    .prologue
    .line 10
    const-string v0, "gamma"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 11
    return-void
.end method

.method public constructor <init>()V
    .locals 0

    .prologue
    .line 5
    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method

.method public static synchronized native declared-synchronized changeGamma(Landroid/graphics/Bitmap;I)V
.end method

.method public static synchronized native declared-synchronized changeGammaARGB8888(Landroid/graphics/Bitmap;I)V
.end method

.method public static synchronized native declared-synchronized changeGammaArray([II)V
.end method

.method public static declared-synchronized changeGammaWrapper(Landroid/graphics/Bitmap;I)V
    .locals 3
    .param p0, "bitmap"    # Landroid/graphics/Bitmap;
    .param p1, "gamma_level"    # I

    .prologue
    .line 14
    const-class v1, Lcom/github/kkspeed/n2kit/Gamma;

    monitor-enter v1

    if-nez p0, :cond_1

    .line 20
    :cond_0
    :goto_0
    monitor-exit v1

    return-void

    .line 15
    :cond_1
    :try_start_0
    invoke-virtual {p0}, Landroid/graphics/Bitmap;->getConfig()Landroid/graphics/Bitmap$Config;

    move-result-object v0

    sget-object v2, Landroid/graphics/Bitmap$Config;->RGB_565:Landroid/graphics/Bitmap$Config;

    if-ne v0, v2, :cond_2

    .line 16
    invoke-static {p0, p1}, Lcom/github/kkspeed/n2kit/Gamma;->changeGamma(Landroid/graphics/Bitmap;I)V
    :try_end_0
    .catchall {:try_start_0 .. :try_end_0} :catchall_0

    goto :goto_0

    .line 14
    :catchall_0
    move-exception v0

    monitor-exit v1

    throw v0

    .line 17
    :cond_2
    :try_start_1
    invoke-virtual {p0}, Landroid/graphics/Bitmap;->getConfig()Landroid/graphics/Bitmap$Config;

    move-result-object v0

    sget-object v2, Landroid/graphics/Bitmap$Config;->ARGB_8888:Landroid/graphics/Bitmap$Config;

    if-ne v0, v2, :cond_0

    .line 18
    invoke-static {p0, p1}, Lcom/github/kkspeed/n2kit/Gamma;->changeGammaARGB8888(Landroid/graphics/Bitmap;I)V
    :try_end_1
    .catchall {:try_start_1 .. :try_end_1} :catchall_0

    goto :goto_0
.end method
