using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Staff
{
    public int StaffId { get; set; }

    public string? Name { get; set; }

    public string? Email { get; set; }

    public string? Phone { get; set; }

    public DateTime? HireDate { get; set; }

    public string? Role { get; set; }

    public int? ManagerId { get; set; }

    public virtual Manager? Manager { get; set; }
}
