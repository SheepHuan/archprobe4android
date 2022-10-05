# 使用

在`archprobe`模块里的`apps/archprobe/app.cpp:line 1691-1705`

```c++
  APP = std::make_unique<ArchProbe>(0);
  APP->clear_aspect_report(clear_aspect);
  (*APP)
    .with_aspect(aspects::warp_size)
    .with_aspect(aspects::gflops)
    .with_aspect(aspects::reg_count)
    .with_aspect(aspects::buf_vec_width)
    .with_aspect(aspects::img_cacheline_size)
    .with_aspect(aspects::buf_cacheline_size)
    .with_aspect(aspects::img_bandwidth)
    .with_aspect(aspects::buf_bandwidth)
    .with_aspect(aspects::const_mem_bandwidth)
    .with_aspect(aspects::local_mem_bandwidth)
    .with_aspect(aspects::img_cache_hierarchy_pchase)
    .with_aspect(aspects::buf_cache_hierarchy_pchase)
  ;
```

选择性注释可能会出错的行

1. 对于华为设备请注释`.with_aspect(aspects::img_cacheline_size)`，该部分执行时无法正确分配内存对象。
2. 对于华为设备请注释`.with_aspect(aspects::const_mem_bandwidth)`，该部分执行时时间测试计算错误。