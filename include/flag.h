#ifndef LIB_TP_FLAG
#define LIB_TP_FLAG

class Flag {
   private:
    uint32_t addr;
    uint8_t bit;

   public:
    void activate();
    void deactivate();
    bool is_active();
    void toggle();
};

#endif  // LIB_TP_FLAG